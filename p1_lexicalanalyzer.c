#include <stdio.h> 
#include <string.h> 
#include <stdbool.h> 
#include <stdlib.h> 
int flagop=0;
int eq=0;
//randvalident=0;
bool isop(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case ',':
        case ';':
        // case '=':
        case '(':
        case ')':
        // case '<':
        // case '>':
        case '[': 
        case ']':
        case '{':
        case '}':return (true);
        default: return (false); 

    }
}

char isrel(char ch)
{
    
    if (ch == '<')
    {
        flagop=1;
        return(true);
        
    }
    else if(ch == '>')
    {
       flagop=2;
        return(true);
    }
    else if (ch == '!')
    {
        flagop=3;
         return(true);
    }
    else if (ch == '=')
    {
        switch(flagop)
        {
            case 1: printf("LE ");flagop=0;
            break;
            case 2: printf("GE ");flagop=0;
            break;
            case 3: printf("NE");flagop=0;
            break;
            case 4: printf("ISEQ ");flagop=0;
            break;
            case 5: printf("OP");flagop=0;
            break;
        }
        flagop=4;
        eq=1;
         return(true);
    }
    
      
}

//  CHECK DELIMITERS
bool isdelim(char ch) 
{ 
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || 
		ch == '/' || ch == ',' || ch == ';' || ch == '>' || 
		ch == '<' || ch == '=' || ch == '(' || ch == ')' || 
		ch == '[' || ch == ']' || ch == '{' || ch == '}') 
		return (true); 
	return (false); 
}
 
bool iskeyword(char* str) 
{ 
	if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") || 
		!strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "int") || !strcmp(str, "double") 
        || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char") 
		|| !strcmp(str, "case") || !strcmp(str, "char") || !strcmp(str, "sizeof") || !strcmp(str, "long") 
		|| !strcmp(str, "short") || !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned") 
		|| !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto")
        || !strcmp(str, "auto") || !strcmp(str, "enum") || !strcmp(str, "register") || !strcmp(str, "extern")
        || !strcmp(str, "union") || !strcmp(str, "for") || !strcmp(str, "signed") || !strcmp(str, "default")
        || !strcmp(str, "goto") || !strcmp(str, "volatile") || !strcmp(str, "const")) 
		return (true); 
	return (false); 
}

bool validIdentifier(char* str) 
{ 
	if (str[0] == '0' || str[0] == '1' || str[0] == '2' || 
		str[0] == '3' || str[0] == '4' || str[0] == '5' || 
		str[0] == '6' || str[0] == '7' || str[0] == '8' || 
		str[0] == '9' || isdelim(str[0]) == true) 
		return (false); 
	return (true); 
} 

bool isint(char* str) 
{ 
	int i, len = strlen(str); 

	if (len == 0) 
		return (false); 
	for (i = 0; i < len; i++) { 
		if (str[i] != '0' && str[i] != '1' && str[i] != '2'
			&& str[i] != '3' && str[i] != '4' && str[i] != '5'
			&& str[i] != '6' && str[i] != '7' && str[i] != '8'
			&& str[i] != '9' || (str[i] == '-' && i > 0)) 
			return (false); 
	} 
	return (true); 
} 

char* subString(char* str, int left, int right) 
{ 
	int i; 
	char* subStr = (char*)malloc( 
				sizeof(char) * (right - left + 2)); 

	for (i = left; i <= right; i++) 
		subStr[i - left] = str[i]; 
	subStr[right - left + 1] = '\0'; 
	return (subStr); 
} 

void compile(char* str) 
{ 
	int left = 0, right = 0; 
	int len = strlen(str); 

	while (right <= len && left <= right) { 
		if (isdelim(str[right]) == false) 
			right++; 

		if (isdelim(str[right]) == true && left == right) { 
			if (isop(str[right]) == true) 
				printf("OP ");
                isrel(str[right]);
                    // if(flagop=5)
                    //     printf("OP"); 

			right++; 
			left = right; 
		} else if (isdelim(str[right]) == true && left != right 
				|| (right == len && left != right)) { 
			char* subStr = subString(str, left, right - 1); 

			if (iskeyword(subStr) == true) 
				printf("KEY "); 

			else if (isint(subStr) == true) 
				printf("NUM ");  

			else if (validIdentifier(subStr) == true
					&& isdelim(str[right - 1]) == false) 
				printf("ID "); 
            

			else if (validIdentifier(subStr) == false
					&& isdelim(str[right - 1]) == false) 
				printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr); 
			left = right; 
            
		} 
	} 
	return; 
} 


int main() 
{ 
	
	char str[100];
    
    printf("HARIKRISHNAN PS _ 23 _ S7 CSE B\n\n");
    printf("Enter the string: ");
    scanf("%[^\n]", str); 

    compile(str);

    return (0); 
} 
