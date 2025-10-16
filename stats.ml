(* Calculate mean using List.fold_left *)
let mean lst =
  let sum = List.fold_left ( +. ) 0.0 (List.map float_of_int lst) in
  sum /. float_of_int (List.length lst)

(* Sort a list *)
let sort_list lst = List.sort compare lst

(* Calculate median *)
let median lst =
  let sorted = sort_list lst in
  let n = List.length sorted in
  if n mod 2 = 0 then
    let a = List.nth sorted (n / 2 - 1)
    and b = List.nth sorted (n / 2) in
    (float_of_int (a + b)) /. 2.0
  else
    float_of_int (List.nth sorted (n / 2))

(* Calculate mode using frequency counting *)
let mode lst =
  let count x = List.length (List.filter ((=) x) lst) in
  let rec find_mode xs current best =
    match xs with
    | [] -> best
    | h :: t ->
        let c = count h in
        let best_c = count best in
        if c > best_c then find_mode t h best else find_mode t current best
  in
  find_mode lst (List.hd lst) (List.hd lst)

let () =
  let numbers = [24; 92; 88; 86; 24; 93; 42] in
  Printf.printf "Mean: %.2f\n" (mean numbers);
  Printf.printf "Median: %.2f\n" (median numbers);
  Printf.printf "Mode: %d\n" (mode numbers)