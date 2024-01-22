,		read first byte from stdin and store in cell#0
>		move to cell#1
,		read 2nd digit from stdin and store in cell#1
[
	<
	+
	[		enter the loop
			move ptr to cell#1 to cell#0
		+	incremente cell#0
		>	move ptr to cell#1
		-	decremente cell#1
		<
	]		exit the loop when cell#1 is 0
	>
	-
]
<		move ptr back to cell#0 which contains result of addition
----------
----------
----------
----------
--------	minus 48 to get ascci
.		print cell#0 (the ascii val)
