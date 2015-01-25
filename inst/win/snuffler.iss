; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define AppName "Snuffler"
#define AppVersion "0.0.1"
#define AppPublisher "Bolsheviks.com"
#define AppURL "http://www.bolsheviks.com/"
#define AppExeName "snuffapp.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{958CD777-257D-4C68-A667-83E6C1F50A62}
AppName={#AppName}
AppVersion={#AppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#AppPublisher}
AppPublisherURL={#AppURL}
AppSupportURL={#AppURL}
AppUpdatesURL={#AppURL}
DefaultDirName={pf}\{#AppName}
DefaultGroupName={#AppName}
OutputDir=output
OutputBaseFilename=setup
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "..\..\Release\snuffapp.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "WinPcap_4_1_3.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\..\mabat\mabat\bin\release\mabat.exe" ; DestDir: "{app}"; Flags: ignoreversion
Source: "..\..\mabat\mabat\bin\release\System.Data.SQLite.dll" ; DestDir: "{app}"; Flags: ignoreversion
Source: "..\..\mabat\mabat\bin\release\x86\SQLite.Interop.dll" ; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\{#AppName}"; Filename: "{app}\mabat.exe"
Name: "{commondesktop}\{#AppName}"; Filename: "{app}\{#AppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\WinPcap_4_1_3.exe"; 
Filename: "{app}\{#AppExeName}"; Parameters: "/registerService";
Filename: "sc.exe"; Parameters: "start snuffapp";

[UninstallRun]
Filename: "sc.exe"; Parameters: "stop snuffapp";
Filename: "{app}\{#AppExeName}"; Parameters: "/unregisterService";
