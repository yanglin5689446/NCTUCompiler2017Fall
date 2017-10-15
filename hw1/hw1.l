%{
#define LIST               strcat(buf, yytext)
#define tokenKeyword(t)    {LIST; if (Opt_T) printf("<KW%s>\n", (t));}
#define token(t)           {LIST; if (Opt_T) printf("<%s>\n", (t));}
#define tokenChar(t)       {LIST; if (Opt_T) printf("<%c>\n", (t));}
#define tokenInteger(t, i) {LIST; if (Opt_T) printf("<%s: %d>\n", #t, (i));}
#define tokenString(t, s)  {LIST; if (Opt_T) printf("<%s: %s>\n", #t, (s));}
#define MAX_LINE_LENG      256

int Opt_S = 1;
int Opt_T = 1;
int linenum = 1;
char buf[MAX_LINE_LENG];
char buf2[MAX_LINE_LENG];
%}

%x STRING
%x INLINE_COMMENT
%x MULTILINE_COMMENT

%%
"//"        { LIST; BEGIN INLINE_COMMENT; }
"/*"        { LIST; BEGIN MULTILINE_COMMENT; }
<INLINE_COMMENT>\&[ST][+-]   { 
                                LIST; 
                                if(yytext[1] == 'S' && yytext[2] == '+')Opt_S = 1;
                                else if(yytext[1] == 'S' && yytext[2] == '-')Opt_S = 0;
                                else if(yytext[1] == 'T' && yytext[2] == '+')Opt_T = 1;
                                else if(yytext[1] == 'T' && yytext[2] == '-')Opt_T = 0;
                            }
<INLINE_COMMENT>.       { LIST; }
<INLINE_COMMENT>\n      { 
                          LIST; 
                          BEGIN INITIAL;
                          if (Opt_S)
                            printf("%d: %s", linenum, buf);
                          linenum++;
                          buf[0] = '\0';
                        }
<MULTILINE_COMMENT>\n      { 
                          LIST; 
                          BEGIN INITIAL;
                          if (Opt_S)
                            printf("%d: %s", linenum, buf);
                          linenum++;
                          buf[0] = '\0';
                        }
<MULTILINE_COMMENT>.    { LIST; }
<MULTILINE_COMMENT>\*\/ { LIST; BEGIN INITIAL;}
<INITIAL>\"                    { LIST; memset(buf2, 0, sizeof(buf2)); BEGIN STRING;}
<STRING>\n                     { printf("Error: newline in string constant\n"); return 1;}
<STRING>\"\"                   { LIST; strcat(buf2, "\""); }
<STRING>\"                     { LIST; tokenString(string, buf2); BEGIN INITIAL; }
<STRING>.                      { LIST; strcat(buf2, yytext);}
^[ ]*       { ; }
array		{ tokenKeyword(yytext); }
begin		{ tokenKeyword(yytext); }
boolean		{ tokenKeyword(yytext); }
def		    { tokenKeyword(yytext); }
do		    { tokenKeyword(yytext); }
else		{ tokenKeyword(yytext); }
end		    { tokenKeyword(yytext); }
false		{ tokenKeyword(yytext); }
for		    { tokenKeyword(yytext); }
integer		{ tokenKeyword(yytext); }
if		    { tokenKeyword(yytext); }
of		    { tokenKeyword(yytext); }
print		{ tokenKeyword(yytext); }
read		{ tokenKeyword(yytext); }
real		{ tokenKeyword(yytext); }
string		{ tokenKeyword(yytext); }
then		{ tokenKeyword(yytext); }
to		    { tokenKeyword(yytext); }
true		{ tokenKeyword(yytext); }
return		{ tokenKeyword(yytext); }
var		    { tokenKeyword(yytext); }
while		{ tokenKeyword(yytext); }

":="  { token(yytext); }
">="  { token(yytext); }
"<="  { token(yytext); }
"=="  { token(yytext); }
">"  { token(yytext); }
"<"  { token(yytext); }
"="  { token(yytext); }
\+	{ token(yytext); }
\-	{ token(yytext); }
\*	{ token(yytext); }
\/  { token(yytext); }
mod  { token(yytext); }
and  { token(yytext); }
or  { token(yytext); }
not  { token(yytext); }
,	{ token(yytext); }
;	{ token(yytext); }
:	{ token(yytext); }
\(	{ token(yytext); }
\)	{ token(yytext); }
\[	{ token(yytext); }
\]	{ token(yytext); }

[0-9]*\.[0-9]+([eE][\+-][0-9]+) { tokenString(scientific, yytext); }
[1-9][0-9]*                     { tokenString(integer, yytext); }
0[0-9]*                         { tokenString(oct_integer, yytext); }
0[xX][0-9]*                     { tokenString(hex_integer, yytext); }
[0-9]*\.[0-9]+                  { tokenString(float, yytext); }
[a-zA-Z_][a-zA-Z0-9_]*          { tokenString(id, yytext); }
\n          {
              LIST;
              if (Opt_S)
                printf("%d: %s", linenum, buf);
              linenum++;
              buf[0] = '\0';
            }
.           { LIST; }
%%
int main( int argc, char **argv )
{
  if( argc != 2 ) {
    fprintf( stderr, "Usage: ./scanner [filename]\n" );
    exit(0);
  }
	
  FILE *fp = fopen( argv[1], "r" );
  if( fp == NULL ) {
    fprintf( stderr, "Open file error\n" );
    exit(-1);
  }
	
  yyin = fp;

  yylex();

  exit(0);
}
