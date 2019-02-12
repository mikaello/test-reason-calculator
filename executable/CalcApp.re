open Cmdliner;
open Calc;
open Pastel;

let version = "1.0.0";

let print_result = result =>
  Pastel.(
    <Pastel>
      <Pastel color=Blue> "Result: " </Pastel>
      <Pastel bold=true> {string_of_int(result)} </Pastel>
    </Pastel>
  )
  |> print_endline;

let default = (
  Term.(ret(const(_ => `Help((`Pager, None))) $ const())),
  Term.info("calc", ~version),
);

let add = {
  let x =
    Arg.(
      value & pos(0, int, 0) & info([], ~docv="number", ~doc="First number")
    );
  let y =
    Arg.(
      value & pos(1, int, 0) & info([], ~docv="number", ~doc="Second number")
    );

  let multiply =
    Arg.(value & flag & info(["m", "multiply"], ~doc="Gang istedenfor"));

  (
    Term.(
      const((x, y, multiply) =>
        if (multiply) {
          print_result(x * y);
        } else {
          print_result(Calculator.add(x, y));
        }
      )
      $ x
      $ y
      $ multiply
    ),
    Term.info("add", ~version),
  );
};

let _ = Term.eval_choice(default, [add]) |> Term.exit;