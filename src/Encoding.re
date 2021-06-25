module E = Decoders_yojson.Basic.Encode;

type role =
  | Admin
  | User;

type user = {
  name: string,
  roles: list(role),
};
module My_encoders = (E: Decoders.Encode.S) => {
  open E;

  let role: encoder(role) = (
    fun
    | Admin => string("ADMIN")
    | User => string("USER"):
      encoder(role)
  );

  let user: encoder(user) = (
    u => obj([("name", string(u.name)), ("roles", list(role, u.roles))]):
      encoder(user)
  );
};

module My_yojson_encoders = My_encoders(Decoders_yojson.Basic.Encode);

open My_yojson_encoders;

let users = [
  {name: "Alice", roles: [Admin, User]},
  {name: "Bob", roles: [User]},
];
let usersEncodedString = E.encode_string(E.obj, [("users", E.list(user, users))]);

// print_endline(users)
print_endline(usersEncodedString);
