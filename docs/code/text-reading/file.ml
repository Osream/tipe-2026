let file_to_line_list filename =
  let ic = open_in filename in
  let rec aux acc =
    try
      let line = input_line ic in
      aux (line :: acc)
    with End_of_file ->
      close_in ic;
      List.rev acc
  in
  aux []

let is_special_char c =
  match c with
  | ' ' | '\n' | '\t' | ',' | '.' | ';' | ':' | '!' | '?' | '"' | '\'' | '(' | ')' | '[' | ']' | '{' | '}' | '$' | '%' | '&' | '*' | '+' | '-' | '/' | '<' | '=' | '>' | '@' | '^' | '|' | '~' | '#' -> true
  | _ -> false

let word_separator list =
  let rec aux list =
    match list with
    | [] -> []
    | word::rest ->
      let new_word = ref "" in
      let acc = ref (aux rest) in
      let n = String.length word in
      if n <> 0 then
        (let change = ref (is_special_char word.[n-1]) in
        for i = n-1 downto 0 do
          let is_spec = is_special_char word.[i] in
          if not (is_spec = !change) then begin
            acc := (!new_word)::(!acc);
            new_word := String.make 1 word.[i];
            change := is_spec
          end
          else
            new_word := String.make 1 word.[i] ^ !new_word;
            if i = 0 then
              acc := (!new_word)::(!acc)
        done;);
      !acc
    in aux list
      
let rec detect_double_parentheses lst =
  match lst with
  | [] -> []
  | word::rest -> match String.length word with
      | 2 ->
          (match word with
          | "((" -> "("::"("::(detect_double_parentheses rest)
          | "))" -> ")"::")"::(detect_double_parentheses rest)
          | "{{" -> "{"::"{"::(detect_double_parentheses rest)
          | "}}" -> "}"::"}"::(detect_double_parentheses rest)
          | "[[" -> "["::"["::(detect_double_parentheses rest)
          | "]]" -> "]"::"]"::(detect_double_parentheses rest)
          | _ -> word :: (detect_double_parentheses rest))
      | _ ->
          word :: (detect_double_parentheses rest)


let file_to_list filename = 
  let l_lst = file_to_line_list filename in
  
  let rec aux lst = 
    match lst with
    | [] -> []
    | line :: rest ->
        let suite = aux rest in
        let word = ref "" 
        and n = String.length line in

        let rec aux i acc = 
          if i = -1 then
            !word :: acc
          else (
            match line.[i] with
            | c when c = ' ' -> 
                let new_acc = !word :: acc in
                word := "";
                aux (i - 1) new_acc
            | c -> 
                word := String.make 1 c ^ !word;
                aux (i - 1) acc
          )
          in
          aux (n-1) suite
    in
    let res = aux l_lst in
    detect_double_parentheses (word_separator res)



let list_to_file lst filename =
  let oc = open_out filename in
  let rec aux lst =
    match lst with
    | [] -> ()
    | word::rest ->
      output_string oc (word ^ "\n");
      aux rest
  in
  aux lst;
  close_out oc