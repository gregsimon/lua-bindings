-- Test for zx


local v = zx.vmo_create();
local s = zx.socket_create();

print("a vmo is = "); print(v);

print("vmo.foo="); print(v:foo());
print("socket.foo="); print(s:foo());

-- loose reference to the vmo obj.
v = 0;
s = 0;

-- this will cause the vmo to be cleared, and it's
-- destructor called.
collectgarbage("collect");

