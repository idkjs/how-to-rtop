
# Trying Ocaml-Decoders

This seems to work:
via [discord](https://discord.com/channels/235176658175262720/235200837608144898/858081629889232967)
```sh
> rtop
...
Type #utop_help for help about using utop.

Reason # #require "decoders";
Reason # #require "decoders-yojson";
<!-- define whatever module -->
Reason # module E = Decoders_yojson.Basic.Encode;
module E =
  Decoders_yojson.Basic.Encode;
Reason #
```

Also see [#use_output "dune top";](https://dune.readthedocs.io/en/stable/toplevel-integration.html#toplevel-integration)

# Running

```sh
make all
dune exec src/Encoding.exe
dune exec generic/GenericDecoders.exe
# or
make test
```
# Goals

## Return values
How to process the decoder return values and use them.

`D.encode`?

## How to run in `rtop`.


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

