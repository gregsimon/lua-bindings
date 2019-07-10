-- Lua Generator for bindings

local inspect = require('inspect')
local cjson = require('cjson')
local fidl = require('fidl')

generate_fidl_from_json = function (fidl_json)
    decoded_json = cjson.decode(fidl_json);

    module_source = fidl.generate_module(decoded_json);
    
    local f = assert(io.open("output.lua", "w"));
    f:write(module_source);
    f:close();
end

-- Calculate --

-- Command line interface --
local f = assert(io.open(arg[1], "r"));
local jsonBody = f:read("*all");
f:close();

generate_fidl_from_json (jsonBody);

