; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!
#define AppName "IoN"
#define AppVersion "0.0.5"
#define AppPublisher "Lagildo"
#define AppURL "http://www.lagildo.com/"
#define AppExeName "ion.exe"
#define BINDIR "..\..\Release"

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
DefaultDirName={pf}\{#AppPublisher}\{#AppName}
DefaultGroupName={#AppName}
OutputDir={#BINDIR}
OutputBaseFilename={#AppName}_setup_{#AppVersion}
Compression=lzma
SolidCompression=yes

[Code]
#include "services.iss"

procedure CurStepChanged(CurStep: TSetupStep);
var 
  executable: String;
begin
  if (CurStep=ssPostInstall) then 
  begin
    executable := ExpandConstant('{app}') + '\{#AppExeName}';    
    SimpleCreateService('{#AppName}','{#AppPublisher} {#AppName} Network Monitor',executable,SERVICE_AUTO_START,'','',false,false);
    SimpleStartService('{#AppName}',true,true);
  end;
end;

function InitializeUninstall : Boolean;
begin
  SimpleStopService('#{AppName}',true,true);  
  SimpleDeleteService('#{AppName}');
  Result:=true;
end;

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "{#BINDIR}\ion.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "WinPcap_4_1_3.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#BINDIR}\ion.db"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\..\ion\ion.properties"; DestDir: "{app}\config"; Flags: ignoreversion

Source: "..\..\web\*"; DestDir: "{app}\web"; Flags: recursesubdirs 

[Icons]
Name: "{group}\ion"; Filename: "http://localhost:9980/things.bin"; 

[Run]
Filename: "{app}\WinPcap_4_1_3.exe"; 

[UninstallDelete]
Type: filesandordirs; Name: "{app}"