# LyraUINavigation
Lyra's UI Navigation logic extracted into its own plugin

Copy the following plugins from the Lyra Starter Game project. There is no need to enable them manually, as they will be automatically enabled as dependencies of the LyraUINavigation plugin:
- CommonGame
- CommonLoadingScreen
- CommonUser
- GameSettings
- ModularGameplayActors

After adding this plugin to your project and enabling it, be sure to:
- Go to Project Settings and update the following properties:
  - [Project / Maps & Modes] -> Game Instance Class = LyraUINavGameInstance
  - [Game / Common Input Settings] -> Input Data = B_CommonInputData
  - [Engine / General Settings] -> Game Viewport Client Class = LyraGameViewportClient
  - [Engine / General Settings] -> Local Player Class = LyraLocalPlayer
  - [Engine / General Settings] -> Game User Settings Class = LyraSettingsLocal
  - [Plugins / Lyra UI Navigation] -> Default UI Policy Class = B_LyraUIPolicy
  - [Game /LyraAudioSettings] -> Default Control Bus Mix -> CBM_BaseMix
  - [Game /LyraAudioSettings] -> Loading Screen Control Bus Mix -> CBM_LoadingScreenMix
  - [Game /LyraAudioSettings] -> User Settings Control Bus Mix -> CBM_UserMix
  - [Game /LyraAudioSettings] -> Overall Volume Control Bus -> CB_Main
  - [Game /LyraAudioSettings] -> Music Volume Control Bus -> CB_Music
  - [Game /LyraAudioSettings] -> Sound FXVolume Control Bus -> CB_SFX
  - [Game /LyraAudioSettings] -> Dialogue Volume Control Bus -> CB_Dialogue
  - [Game /LyraAudioSettings] -> Voice Chat Volume Control Bus -> CB_VoiceChat
  - [Game /Common Loading Screen] -> W_LoadingScreen_Host
  - [Plugins / Common UI Input Settings] -> Input Actions -> UI.Action.Escape -> Your selected escape keys

- Use the plugin's BP_LUIN_PlayerController or have your Player Controller class inherit from CommonPlayerController

- Edit DefaultGame.ini and add the following line
  ```
  [/Script/LyraUINavigation.LyraUIMessaging]
  ConfirmationDialogClass=/LyraUINavigation/UI/Foundation/Dialogs/W_ConfirmationDefault.W_ConfirmationDefault_C
  ErrorDialogClass=/LyraUINavigation/UI/Foundation/Dialogs/W_ConfirmationError.W_ConfirmationError_C
  ```
