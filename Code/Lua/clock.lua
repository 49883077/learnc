local startTime = os.clock();
local s = 0;
for i = 1, 1000000  do
   	local x = math.sin(i)
end
local endTime = os.clock()
print(string.format("startTime : %.2f---endTime : %.2f\n", startTime,endTime));

local startTime2 = os.clock();
local sin = math.sin
for i = 1, 1000000  do
   	local x = sin(i)
end
local endTime2 = os.clock()
print(string.format("startTime : %.2f---endTime : %.2f\n", startTime2,endTime2));


