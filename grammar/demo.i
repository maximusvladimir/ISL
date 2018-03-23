var myValue := 10
var myValue := 20
func noReturn()
	writeln()
	writeln("Hello World")

if 10 = 10
	writeln("10 = 10!")
else if 10 = 11
	writeln("10 = 11!")
	if (1 = 1)
		writeln("Okay good.")
else
	writeln("Something weird happened.")

i32 func get_first(list t)
	return t@0

i8 func getMyNumber()
	return 10

writeln(getMyNumber())

foreach i from 0 to 10
	writeln("Hello #" + i)

var set1 := {0, 1, 2, 3, 4, 4}

var leen2 := [0, 1, 2, 3, 4, 5]

writeln(set1@0)
writeln("Value of list, leen2, at index #2: " + leen2@(2))
writeln("Sublist of list, leen2, from index #2 to index # 4: " + leen@(2, 4))

i32 func pseudoMult(ui32 num1, num2)
	i32 result
	num1 := abs(num1)
	num2 := abs(num2)
	foreach i from 1 to num1
		result += num2
	return result

writeln(pseudoMult(10, 10) + " should equal 100")

writeln("Power test: 10^3 = " + 10 ^ 3.0f)

noReturn()

string upperCased := "HELLO WORLD!"
call("user32.dll", "CharLowerBuffer", upperCased, |upperCased|)
sysd("cd .. & mkdir mynewdir & cd mynewdir & \"hello there\" >> dumped.txt")
var output := sysd("echo pwd")
writeln("Current working directory: " + output)

/*
built-in functions:
<anything> call(library, functionName, ...)
string sysd(command)
writeln(text)
write(text)
i64 datetime(text)
<any number> max(...)
<any number> min(...)
<any number> abs(number)
<f32 or f64> cos(number)
<f32 or f64> tan(number)
<f32 or f64> sin(number)
<f32 or f64> acos(number)
<f32 or f64> atan(number)
<f32 or f64> asin(number)
<f32 or f64> atan2(number1, number2)
<f32 or f64> round(number)
<f32 or f64> ceil(number)
<f32 or f64> floor(number)
use(text)
i8 i8(val)
i16 i16(val)
i32 i32(val)
i64 i64(val)
ui8 ui8(val)
ui16 ui16(val)
ui32 ui32(val)
ui64 ui64(val)
f32 f32(val)
f64 f64(val)
file fopen(fileName, mode)
i32 ferror(file)
string ferrormsg(errorCode)
fclose(file)
*/