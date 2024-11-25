# LyraUINavigation
Lyra's UI Navigation logic extracted into its own plugin

Copy the following plugins from the Lyra Starter Game project. There is no need to enable them manually, as they will be automatically enabled as dependencies of the LyraUINavigation plugin:
- CommonGame
- CommonUser
- GameSettings
- ModularGameplayActors

After adding this plugin to your project and enabling it, be sure to:
- Go to Project Settings and update the following properties:
  - [Project / Maps & Modes] -> Game Instance Class = LyraUINavGameInstance
  - [Game / Common Input Settings]-> Input Data = B_CommonInputData
  - [Engine / General Settings] -> Game Viewport Client Class = LyraGameViewportClient
  - [Engine / General Settings] -> Local Player Class = LyraLocalPlayer
  - [Engine / General Settings] -> Game User Settings Class = LyraSettingsLocal
  - [Plugins / Lyra UI Navigation] -> Default UI Policy Class = B_LyraUIPolicy
- Use the plugin's BP_LUIN_PlayerController or have your Player Controller class inherit from CommonPlayerController
