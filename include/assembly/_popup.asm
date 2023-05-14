	invoke	MessageBox,HWND_DESKTOP,"Am i a program made by Pontus?",invoke GetCommandLine,MB_YESNO

	.if eax = IDYES
		invoke	MessageBox,HWND_DESKTOP,"You're correct. I am made by Pontus <3","Pontus's program!",MB_OK
	.endif

       .if eax = IDNO
		invoke	MessageBox,HWND_DESKTOP,"You're wrong. I am made by Pontus :3","Pontus's program!",MB_OK
	.endif