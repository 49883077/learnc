collectgarbage("collect")
local s1 = collectgarbage("count")
print(">>>>>>>>count=",s1)
local my_list = {}
for i=1,100 do
	local v = {100,200}
	my_list[i] = v
end
local s2 = collectgarbage("count")
print(">>>>>>>>count=",s2)
my_list = nil
collectgarbage("collect")

local s3 = collectgarbage("count")
print(">>>>>>>>count=",s3)