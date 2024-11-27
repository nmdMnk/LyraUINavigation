# LyraUINavigation
Lyra's UI Navigation logic extracted into its own plugin

Copy the following plugins from the Lyra Starter Game project. There is no need to enable them manually, as they will be automatically enabled as dependencies of the LyraUINavigation plugin:
- CommonGame
- CommonLoadingScreen
- CommonUser
- GameSettings
- ModularGameplayActors

After adding this plugin to your project and enabling it, be sure to:
- Copy all the *platform folders* in [LyraUINavigation Directory] / Config into your project's Config folder.
- Go to Project Settings and update the following properties:
  - [Project / Maps & Modes] -> Game Instance Class = LyraUINavGameInstance
  - [Game / Common Input Settings] -> Input Data = B_CommonInputData
  - [Engine / General Settings] -> Game Viewport Client Class = LyraGameViewportClient
  - [Engine / General Settings] -> Local Player Class = LyraLocalPlayer
  - [Engine / General Settings] -> Game User Settings Class = LyraSettingsLocal
  - [Plugins / Lyra UI Navigation] -> Default UI Policy Class = B_LyraUIPolicy
  - [Plugins / Common UI Input Settings] -> Input Actions -> UI.Action.Escape -> Your selected escape keys
  - [Game /LyraUIMessagingSettings] -> Confirmation Dialog Class -> W_ConfirmationDefault
  - [Game /LyraUIMessagingSettings] -> Error Dialog Class -> W_ConfirmationError
  - [Game /Common Loading Screen] -> W_LoadingScreen_Host
  - [Game /LyraAudioSettings] -> Default Control Bus Mix -> CBM_BaseMix
  - [Game /LyraAudioSettings] -> Loading Screen Control Bus Mix -> CBM_LoadingScreenMix
  - [Game /LyraAudioSettings] -> User Settings Control Bus Mix -> CBM_UserMix
  - [Game /LyraAudioSettings] -> Overall Volume Control Bus -> CB_Main
  - [Game /LyraAudioSettings] -> Music Volume Control Bus -> CB_Music
  - [Game /LyraAudioSettings] -> Sound FXVolume Control Bus -> CB_SFX
  - [Game /LyraAudioSettings] -> Dialogue Volume Control Bus -> CB_Dialogue
  - [Game /LyraAudioSettings] -> Voice Chat Volume Control Bus -> CB_VoiceChat
  - [Plugins / Common UI Editor] -> Template Text Style -> TextStyle-Regular
  - [Plugins / Common UI Editor] -> Template Button Style -> ButtonStyle-Primary-M
  - [Plugins / Common UI Framework] -> Default Throbber Material -> M_UI_Throbber_Base
  - [Plugins / Common UI Framework] -> Default Rich Text Data Class -> CommonUIRichTextData

- Test the FrontEnd Menu with L_LyraFrontEnd level
- Use the plugin's BP_LUIN_PlayerController or have your Player Controller class inherit from CommonPlayerController

Otherwise, you can configure these settings by editing .ini files.

Alter **DefaultEngine.ini** with the following settings:
  - **[/Script/EngineSettings.GameMapsSettings]**
  ```
  GameInstanceClass=/Script/LyraUINavigation.LyraUINavGameInstance
  ```
  - **[/Script/Engine.Engine]**
  ```
  GameViewportClientClassName=/Script/LyraUINavigation.LyraGameViewportClient
  LocalPlayerClassName=/Script/LyraUINavigation.LyraLocalPlayer
  GameUserSettingsClassName=/Script/LyraUINavigation.LyraSettingsLocal
  ```

  Alter **DefaultEngine.ini** and add the following lines:
  - **Common UI Editor**
  ```
  [/Script/CommonUI.CommonUIEditorSettings]
  TemplateTextStyle=/LyraUINavigation/UI/Foundation/Text/TextStyle-Regular.TextStyle-Regular_C
  TemplateButtonStyle=/LyraUINavigation/UI/Foundation/Buttons/ButtonStyle-Primary-M.ButtonStyle-Primary-M_C
  ```

  Alter **DefaultGame.ini** and add the following lines:
  - **Common Input Settings**
  ```
  [/Script/CommonInput.CommonInputSettings]
  InputData=/LyraUINavigation/UI/B_CommonInputData.B_CommonInputData_C
  ```
  - **Lyra UI Navigation**
  ```
  [/Script/LyraUINavigation.LyraUIManagerSubsystem]
  DefaultUIPolicyClass=/LyraUINavigation/UI/B_LyraUIPolicy.B_LyraUIPolicy_C
  ```
  - **LyraUIMessagingSettings**
  ```
  [/Script/LyraUINavigation.LyraUIMessagingSettings]
  ConfirmationDialogClass=/LyraUINavigation/UI/Foundation/Dialogs/W_ConfirmationDefault.W_ConfirmationDefault_C
  ErrorDialogClass=/LyraUINavigation/UI/Foundation/Dialogs/W_ConfirmationError.W_ConfirmationError_C
  ```
  - **Common Loading Screen**
  ```
  [/Script/CommonLoadingScreen.CommonLoadingScreenSettings]
  LoadingScreenWidget=/LyraUINavigation/UI/Foundation/LoadingScreen/W_LoadingScreen_Host.W_LoadingScreen_Host_C
  ```
  - **LyraAudioSettings**
  ```
  [/Script/LyraUINavigation.LyraAudioSettings]
  DefaultControlBusMix=/LyraUINavigation/Audio/Modulation/ControlBusMixes/CBM_BaseMix.CBM_BaseMix
  LoadingScreenControlBusMix=/LyraUINavigation/Audio/Modulation/ControlBusMixes/CBM_LoadingScreenMix.CBM_LoadingScreenMix
  UserSettingsControlBusMix=/LyraUINavigation/Audio/Modulation/ControlBusMixes/CBM_UserMix.CBM_UserMix
  OverallVolumeControlBus=/LyraUINavigation/Audio/Modulation/ControlBuses/CB_Main.CB_Main
  MusicVolumeControlBus=/LyraUINavigation/Audio/Modulation/ControlBuses/CB_Music.CB_Music
  SoundFXVolumeControlBus=/LyraUINavigation/Audio/Modulation/ControlBuses/CB_SFX.CB_SFX
  DialogueVolumeControlBus=/LyraUINavigation/Audio/Modulation/ControlBuses/CB_Dialogue.CB_Dialogue
  VoiceChatVolumeControlBus=/LyraUINavigation/Audio/Modulation/ControlBuses/CB_VoiceChat.CB_VoiceChat
  +HDRAudioSubmixEffectChain=(Submix="/LyraUINavigation/Audio/Submixes/MainSubmix.MainSubmix",SubmixEffectChain=("/LyraUINavigation/Audio/Effects/SubmixEffects/DYN_MainDynamics.DYN_MainDynamics"))
  +LDRAudioSubmixEffectChain=(Submix="/LyraUINavigation/Audio/Submixes/MainSubmix.MainSubmix",SubmixEffectChain=("/LyraUINavigation/Audio/DYN_LowMultibandDynamics.DYN_LowMultibandDynamics","/LyraUINavigation/Audio/Effects/SubmixEffects/DYN_LowDynamics.DYN_LowDynamics"))
  ```
  - **Common UI Framework**
  ```
  [/Script/CommonUI.CommonUISettings]
  DefaultThrobberMaterial=/LyraUINavigation/UI/Foundation/Materials/M_UI_Throbber_Base.M_UI_Throbber_Base
  DefaultRichTextDataClass=/LyraUINavigation/UI/Foundation/RichTextData/CommonUIRichTextData.CommonUIRichTextData_C
  ```

  Alter **DefaultInput.ini** with the following settings:
  - **[/Script/CommonUI.CommonUIInputSettings]**
  ```
  +InputActions=(ActionTag=UI.Action.Escape,DefaultDisplayName=NSLOCTEXT("[/Script/CommonUI]", "9CEDB5134A81C713ABBF439A9E695D4A", "Back"),KeyMappings=((Key=Escape),(Key=Gamepad_Special_Right)))
  ```


If you experience the issue where the "Default UI Policy Class" resets to "None" after being set in the editor's project settings and restarting the project, resolve it by updating the **DefaultGame.ini** file as explained above in the **Lyra UI Navigation** section.
Alternatively, you can fix the editor's issue by editing **Plugins/CommonGame/Source/Public/GameUIManagerSubsystem.h** and replacing:
  ```
  UCLASS(Abstract, config = Game)
  ```
  with:
  ```
  UCLASS(Abstract, defaultconfig, config = Game)
  ```