module E = Decoders_yojson.Basic.Encode;

type role =
  | Admin
  | User;

type user = {
  name: string,
  roles: list(role),
};

module D = Decoders_yojson.Basic.Decode;
let x = D.decode_value(D.int, `Int(1));
type my_user = {
  name: string,
  age: int,
};
let my_user_decoder: D.decoder(my_user) = (
  D.(
    field("name", string)
    >>= (name => field("age", int) >>= (age => succeed({name, age})))
  ):
    D.decoder(my_user)
);
module My_decoders = (D: Decoders.Decode.S) => {
  open D;
  let role: decoder(role) = (
    string
    >>= (
      fun
      | "ADMIN" => succeed(Admin)
      | "USER" => succeed(User)
      | _ => fail("Expected a role")
    ):
      decoder(role)
  );

  let user: decoder(user) =
    D.(
      field("name", string)
      >>= (
        name =>
          field("roles", list(role)) >>= (roles => succeed({name, roles}))
      )
    );
};

module My_yojson_decoders = My_decoders(Decoders_yojson.Basic.Decode);
open My_yojson_decoders;
let x = D.decode_string(role, {| "USER" |});
// switch (x) {
// | role => role
// };
let x = D.decode_string(D.(field("users", list(user))));
print_endline("nothing to see here yet")
