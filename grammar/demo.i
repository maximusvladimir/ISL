var myValue := 10
var myValue := 20
func noReturn()
	writeln()
	writeln("Hello World")


i8 func getMyNumber()
	return 10

writeln(getMyNumber())

foreach i from 0 to 10
	writeln("Hello #" + i)

i32 func pseudoMult(ui32 num1, num2)
	i32 result
	num1 := abs(num1)
	num2 := abs(num2)
	foreach i from 1 to num1
		result += num2
	return result

writeln(pseudoMult(10, 10) + " should equal 100")

noReturn()

string upperCased := "HELLO WORLD!"
call("user32.dll", "CharLowerBuffer", upperCased, |upperCased|)
sysd("cd .. & mkdir mynewdir & cd mynewdir & \"hello there\" >> dumped.txt")
var output := sysd("echo pwd")
writeln("Current working directory: " + output)
