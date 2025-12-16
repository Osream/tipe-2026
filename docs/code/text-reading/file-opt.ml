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
    aux l_lst