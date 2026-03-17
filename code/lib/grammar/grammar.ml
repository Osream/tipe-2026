type expr =
  | Const_Int of int
  | Const_String of string
  | Const_Bool of bool
  | Const_Char of char
  | Const_Float of float
  | Ident of string
  | Apply of expr * expr
  | Fun of pattern * expr
  | Let of string * expr
  | While of expr * expr * expr
  | Match of expr * (pattern * expr) list
and pattern =
  | Ident of string
  | Pipe of pattern * pattern
  | Constructor of  expr * pattern
  | Underscore
  | Root of pattern
