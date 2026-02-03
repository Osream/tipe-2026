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
;;

let is_special_char c =
  match c with
  | ' ' | '\n' | '\t' | ',' | '.' | ';' | ':' | '!' | '?' | '(' | ')' | '[' | ']' | '{' | '}' | '$' | '%' | '&' | '*' | '+' | '-' | '/' | '<' | '=' | '>' | '@' | '^' | '|' | '~' | '#' -> true
  | _ -> false
;;

let rec reconst_string list = 
  match list with
  | [] -> []
  | line::rest -> match line with
    | "" -> reconst_string rest
    | _ -> (match line.[0] with
      | '\"' -> (let while_condition = ref line 
                and n = ref (String.length line)
                and list_ref = ref rest in
                while (!while_condition).[!n -1] <> '\"' || (!while_condition).[!n -2] = '\\' do
                  if (!while_condition).[!n -2] = '\"' && (!while_condition).[!n -3] <> '\\' then begin
                    list_ref := (String.make 1 (!while_condition).[!n -1])::(!list_ref);
                    while_condition := String.sub (!while_condition) 0 (!n - 1)
                  end
                  else
                    match !list_ref with
                    | word::tail -> n:= !n + String.length word + 1; 
                                    while_condition := !while_condition ^ " " ^ word ; 
                                    list_ref := tail
                    | [] -> failwith ""
                done;
                (!while_condition)::(reconst_string !list_ref)
                )
      | '\'' -> (let n = ref 1 in
                while line.[!n] <> '\'' || line.[!n] <> '\\' do
                  incr n
                done;
                (String.sub line 0 (!n + 1)) :: (String.sub line (!n) (String.length line - !n -1)) :: reconst_string rest
      )
      | _ -> line :: (reconst_string rest))
;;


let rec word_separator list =
  match list with
  | [] -> []
  | word::rest ->
    let new_word = ref "" in
    let acc = ref (word_separator rest) in
    if word.[0] <> '\"' && word.[0] <> '\'' then begin
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
        done;
      );
      !acc
    end
    else
      word::(word_separator rest)
;;

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
          | _ -> word :: (detect_double_parentheses rest)
          )
      | _ ->
          word :: (detect_double_parentheses rest)
;;
      
let rec detect_semicolon lst =
  match lst with
  | [] -> []
  | word::rest -> ( let new_word = ref "" in
  if word <> "" then begin
    while
  end;
    (!new_word)::detect_semicolon rest
  )
;;


let file_to_list filename = 
  let l_lst = file_to_line_list filename in
  
  let rec line_to_words lst = 
    match lst with
    | [] -> []
    | line :: rest ->
        let suite = line_to_words rest in
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
    let res = line_to_words l_lst in
    detect_double_parentheses (detect_semicolon (word_separator (reconst_string res)))
;;



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
;;