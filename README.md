
# Trying Ocaml-Decoders

# Goals

How to run in `rtop`.

Whatever the command is, I have not found it.

```sh
Type #utop_help for help about using utop.

Reason # user;
Line 1, characters 0-4:
Error: Unbound value user
Reason # #use "./src/Encoding.re";
File "./src/Encoding.re", line 1, characters 11-39:
1 | module E = Decoders_yojson.Basic.Encode;
               ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Error: Unbound module Decoders_yojson
Reason #
…-log-viewer-decoders (reason-dune)  dune utop .
─────────────────────────────────────
utop version 2.7.0 (using OCaml versi
─────────────────────────────────────

Type #utop_help for help about using utop.

─( 21:26:58 )─< command 0 >─{ counter
utop # #use "rtop"
;;
Cannot find file rtop.
─( 21:26:59 )─< command 1 >─{ counter
utop # #require "rtop";;
Reason # #use "decoders-yojson";
Cannot find file decoders-yojson.
Reason # #use "./src/Encoding.re";
File "./src/Encoding.re", line 1, characters 11-39:
1 | module E = Decoders_yojson.Basic.Encode;
               ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Error: Unbound module Decoders_yojson
Reason # #pwd
;
/Users/mando/Github/zulip-log-viewer-decoders
Reason # #use "./src/Encoding.re";
File "./src/Encoding.re", line 1, characters 11-39:
1 | module E = Decoders_yojson.Basic.Encode;
               ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Error: Unbound module Decoders_yojson
Reason #
```

