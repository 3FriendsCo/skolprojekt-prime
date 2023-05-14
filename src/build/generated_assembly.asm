; ----------------------------------------------------------------------------------|
; Assembly version: x86_64 (AMD_64)                                                 |
;                                                                                   |
; Copyright (c) 2023, 3FriendsCo                                                    |
; Authors: Pontus Henriksson & Neo Mannskär                                         |
;                                                                                   |
; Licensed under the MIT License. You may not use this file except in compliance    |
; with the License. You may obtain a copy of the License at:                        |
;                                                                                   |
; - https://opensource.org/licenses/MIT                                             |
;                                                                                   |
; ----------------------------------------------------------------------------------|

include 'INCLUDE/win64ax.inc' ; you can simply switch between win32ax, win32wx, win64ax and win64wx here

.code
start:

	invoke	MessageBox,HWND_DESKTOP,"Am i a program made by Pontus?",invoke GetCommandLine,MB_YESNO

	.if eax = IDYES
		invoke	MessageBox,HWND_DESKTOP,"You're correct. I am made by Pontus <3","Pontus's program!",MB_OK
	.endif

    .if eax = IDNO
		invoke	MessageBox,HWND_DESKTOP,"You're wrong. I am made by Pontus :3","Pontus's program!",MB_OK
	.endif

invoke ExitProcess,0

.end start


; Program complete!