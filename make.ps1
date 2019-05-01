param(
	[switch] $clean
)

# ./make.ps1 -clean
if ( $clean -eq $true )
{
	del overflow.exe
	exit
}

$name   = "overflow"
$cc     = "gcc"
$source = "main.c overflow.c"
$cflags = "-Wall"

#& $cc -o $name $source $cflags

gcc -o overflow main.c overflow.c -Wall