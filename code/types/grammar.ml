type expr =
  | Constant of int
  | Ident of string
  | Apply of expr * expr
  | Fun of pattern * expr
  | Let of string * expr * expr
  | Match of expr * (pattern * expr) list
and pattern =
  | Ident of string
  | Pipe of pattern * pattern
  | Constructor of  expr * pattern
  | Underscore
  | Root of pattern
