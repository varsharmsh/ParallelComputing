import re,sys,time
from threading import Thread

#defining regular expressions

REGEX_NUMBER = re.compile('(-?[0-9]+(\.[0-9]+)?)');
REGEX_IDENTIFIER = re.compile('[_a-zA-Z][_a-zA-Z0-9]*')
REGEX_COMMENTS=re.compile("((\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/)|(\/\/.*))(\n|\s|\t)(((\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/)|(\/\/.*))\n|\t|\s)*");
REGEX_KEYWORDS = re.compile("auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|const|float|short|unsigned|continue|for|signed|void|default|goto|sizeof|volatile|do|if|static|while");
REGEX_OPERATORS=re.compile ("\|\||&&|<<|>>|--|\+\+|->|==|=|(?:<<|>>|\+|-|\*|\/|%|&|\||\^|<|>|!)=?");
REGEX_LITERALS = re.compile("\".*\"");
REGEX_PUNCTS = re.compile("{|}|;|\(|\)|\,|\[|\]");

#defining global variables
if len(sys.argv) < 2:

	print ("Usage -testFile");

	exit(0);

fileName=sys.argv[1];
scanned=0;
tokens=list();
newToken=None;
code="";
REGEX_TYPES = [[REGEX_NUMBER,'number'],[REGEX_KEYWORDS,'keyword'], [REGEX_IDENTIFIER,'identifier'], [REGEX_OPERATORS,'operator'] ,[REGEX_LITERALS,'literal'],[REGEX_PUNCTS,'punctuation']];
unmatched = list();
#general token class 
class token:
    def __init__(self,value,tokenType):
        self.value = value;
        self.tokenType = tokenType;
        
#remove comments from the code
def removeComments ():
    return REGEX_COMMENTS.sub('',code);

#helper function that scans for regular expressions in parallel
def getToken(regex_type):
    global newToken;
    regex = re.compile(regex_type[0]);
    tokenType= regex_type[1];
    newToken1=None;
    entered = False;
    if not newToken:
        match = regex.findall(code);
        if match:
            entered=True;
            if isinstance(match[0],tuple) and code.find(match[0][0])==0:
                newToken = token(match[0][0], tokenType);
            elif isinstance(match[0],str) and (code.strip()).find(match[0])==0:                
                newToken = token(match[0],tokenType);
                    
    
#functions that populates list tokens() 
def tokenise():
    global code,newToken, workers;
    while code:
        while code and (code[0] == ' ' or code[0]=='\n' or code[0]=='\r'):
            code=code[1:];
        if code:
            newToken = None;
            threads = list();
            for i in range(len(REGEX_TYPES)):
                threads.append(Thread(target = getToken(REGEX_TYPES[i])));
                threads[i].start();
            ob= newToken;
            if ob:
                offset=len(ob.value);
                tokens.append(ob);
                scanned  = offset;
            else:
                unmatched.append(code[0]);
                scanned =1;                
            code = code[scanned :];
       
        
if __name__ == "__main__":  
    f=open(fileName);
    code = f.read();
    code = removeComments();
    #print(code);
    start = time.time();
    tokenise();
    end = (time.time()-start)*1000;
    print len(tokens),end;
    #print(unmatched);
       
