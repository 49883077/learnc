tbl1 = {"1","2",nil,66,nil,"4","5","6"}


function printargs( ... )
	local num_args = select("#",...)
	for i=1,num_args do
		local arg = select(i, ...)
		print(i, arg)
	end
end
printargs("1","2","3",66,nil,"4","5","6")
print("====================================")
function printargs2(...)
	local tbl = {...}
	for i = 1, #tbl do
		print(i, tbl[i])
	end
end
printargs2("1","2","3",66,nil,"4","5","6")
