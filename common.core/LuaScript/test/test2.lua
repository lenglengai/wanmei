function test2(nMySub)
	local result = nMySub:fun0(2)
	print(result)
	if 5 == result then
		return true
	end
	return false
end
