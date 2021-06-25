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
