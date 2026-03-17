open Token;;
open Grammar;;

let analyse_let tok_list =

;;

let rec parse tok_list =
  match tok_list with
  | SEMICOLONCOLON::q -> parse q
  | LET::q -> (
    let expression, tail = analyse_let tok_list 
    in 
    expression::parse tail
  )
  | OPEN::IDENT s::SEMICOLONCOLON::q -> Ident s::parse q
  | _ -> failwith "syntax error"
;;