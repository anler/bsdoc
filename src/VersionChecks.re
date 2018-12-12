open OS;
open Js.Console;

let opam = "opam";
let odoc = "odoc";

let check = () => {
  let has_opam_in_path = run(opam, ["--version"]);
  if (!has_opam_in_path) {
    log(
      {j| 🔥 Could not find the needed odoc binary in your PATH.

To install it, follow instructions in: http://opam.ocaml.org/doc/Install.html

Then try again 🙌🏼
|j},
    );
    exit(1);
  };

  let good_switch = "4.02.3+buckle-master";
  let installed_switch = exec({j|$opam switch show|j});
  let has_good_switch = installed_switch === good_switch;
  if (!has_good_switch) {
    log(
      {j| 🔥 Could not find the needed opam switch: $good_switch.

Instead found: $installed_switch.

To install it, make sure you have `opam` installed and execute:

    opam switch create $good_switch
    eval \$(opam env)

Then try again 🙌🏼
|j},
    );
    exit(1);
  };

  let has_odoc_pkg = run(opam, ["show", odoc]);
  if (!has_odoc_pkg) {
    log(
      {j| 🔥 Could not find the needed odoc package.

To install it, make sure you have `opam` installed and execute:

    opam install odoc

Then try again 🙌🏼
|j},
    );
    exit(1);
  };

  let has_odoc_in_path = run(odoc, ["--version"]);
  if (!has_odoc_in_path) {
    log(
      {j| 🔥 Could not find the needed odoc binary in your PATH.

To install it, make sure you have `opam` installed and execute:

    opam install odoc

Then try again 🙌🏼
|j},
    );
    exit(1);
  };
};
