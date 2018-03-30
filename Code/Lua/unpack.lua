local t = 
{
    [1] = "first",
    [2] = "second",
    [3] = "third",
    [4] = "fourth",
    [5] = "fifth"
}
 
local two, three, four = unpack( t, 2, 3 )
 
print( two, three, four )