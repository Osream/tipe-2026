open Token

let keywords = Hashtbl.create 50
let () =
  List.iter (fun (k, v) -> Hashtbl.add keywords k v) [
    "let", LET;
    "in", IN;
    "fun", FUN;
    "if", IF;
    "then", THEN;
    "else", ELSE;
    "match", MATCH;
    "with", WITH;
    "rec", REC;
    "and", AND;
    "type", TYPE;
    "of", OF;
    "function", FUNCTION;
    "open", OPEN;
    "begin", BEGIN;
    "end", END;
    "for", FOR;
    "while", WHILE;
    "do", DO;
    "done", DONE;
    "try", TRY;
    "catch", CATCH;
  ]
  
let operators = Hashtbl.create 50
let () =
  List.iter (fun (k, v) -> Hashtbl.add operators k v) [
    "+", PLUS;
    "-", MINUS;
    "*", MULT;
    "/", DIV;
    "+.", PLUS;
    "-.", MINUS;
    "*.", MULT;
    "/.", DIV;
    "%", MOD;
    "=", EQ;
    "<-", ASSIGN;
    "<>", NEQ;
    "<", LT;
    ">", GT;
    "<=", LE;
    ">=", GE;
    ":=", ASSIGN;
    "^", CONCAT;
  ]

let delimiters = Hashtbl.create 50
let () =
  List.iter (fun (k, v) -> Hashtbl.add delimiters k v) [
    "(", LPAREN;
    ")", RPAREN;
    "[", LBRACKET;
    "]", RBRACKET;
    "{", LBRACE;
    "}", RBRACE;
    ",", COMMA;
    ".", DOT;
    ";", SEMICOLON;
    "|", PIPE;
    "->", ARROW;
    "=>", DARROW;
    ":", COLON;
    "::", COLONCOLON;
    "\'", QUOT;
    "\"", APOST
  ]

let literal_of_string str =
  match int_of_string_opt str with
  | None -> ( match str with
    | "()" -> UNIT
    | "false" -> BOOL false
    | "true" -> BOOL true
    | s -> IDENT s)
  | Some n -> INT n

let delimiter_of_string str =
  match Hashtbl.find_opt delimiters str with
  | None -> literal_of_string str
  | Some del -> del

let operator_of_string str =
  match Hashtbl.find_opt operators str with
  | None -> delimiter_of_string str
  | Some op -> op

let token_of_string str =
  match Hashtbl.find_opt keywords str with
  | None -> operator_of_string str
  | Some key -> key

let reunite_patterns token_list =
  match token_list with
  | t1::t2::t3::q -> if 
  | _ -> token_list



let tokenize file =
  let ic = open_in file in
  let rec aux acc =
    try
      let line = input_line ic in
      aux ((token_of_string line) :: acc)
    with End_of_file ->
      close_in ic;
      List.rev (EOF::acc)
  in
  reunite_patterns (aux [])