function test1(nMyBase)
	local result = nMyBase:fun1(true)
	print(result)
	if 6 == result then
		return true
	end
	return false
end
