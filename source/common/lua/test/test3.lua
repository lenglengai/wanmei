function test3(nMySub)
	local result = nMySub:fun2(true)
	print(result)
	if 5 == result then
		return true
	end
	return false
end
