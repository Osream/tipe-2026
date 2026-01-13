type token =
  (* Literals *)
  | INT of int
  | STRING of string
  | BOOL of bool
  | CHAR of char
  | FLOAT of float
  | UNIT
  (* Keywords *)
  | LET | IN | FUN | IF | THEN | ELSE | MATCH | WITH
  | REC | AND | TYPE | OF | FUNCTION | OPEN
  | BEGIN | END | FOR | WHILE | DO | DONE | TRY | CATCH 
  (* Identifiers and operators *)
  | IDENT of string
  | PLUS | MINUS | MULT | DIV | MOD
  | EQ | NEQ | LT | GT | LE | GE
  | ASSIGN | CONCAT
  (* Delimiters *)
  | LPAREN | RPAREN | LBRACKET | RBRACKET | LBRACE | RBRACE
  | COMMA | DOT | SEMICOLON | PIPE | ARROW | DARROW
  | COLON | COLONCOLON | QUOT | APOST | EOF