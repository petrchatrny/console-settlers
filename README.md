# CONSOLE SETTLER

## Authors
- Petr Chatrný
- Martin Weiss
- Daniil Astapenko

## UML - class diagram
![Where diagram](./diagram.svg)

## GAME
- ### Rules:
    - player can create buildings only with TownHall
    - player can create buildings only when there are enough resources in TownHall
    - player can create buildings only into EmptyTerrain
    - every building has 100 durability (100 of damage will destroy building) 
    - player can mine resources from terrain with extraction buildings
    - for mining resources from the terrain, the right building must be next to the right terrain
    - LumberjackHouse can mine Forest, StoneQuarry can mine mountains, IronMine can mine moutains and secret cave
    - after mining are resources stored in inventory of extraction buildings
    - player must transfer resources from extraction buildings to TownHall for creating new buildings
    - every transfer of resources can invoke attack of the natives
    - during the game player must face this attack 3 times
    - if the town hall is destroyed during any of these attacks, the player loses
    - every attack is stronger than the previous one and deals more damage
    - during attack buildings are being damaged in order: WeaponBuildings > ExtractionBuildings > MoraleBuildings > PopulationBuildings > TownHall
    - higher number of population and morale can delay attack

- ### Commands:
    - **0** - will write all avaible commands of Game
    - **1** - will print map
    - **2** - will enter the building, user can now use commands of building but not commands of the game
    - **99** - will end the game by surrender


## BUILDINGS
### Attributes
| name            | appearance | cost                          | population | morale | defence |
| --------------- | ---------- | ----------------------------- | ---------- | ------ | ------- |
| TownHall        | 🏛          | 0                             | 0          | 0      | 0       |
| Cottage         | 🏚          | 100 wood                      | 2 - 6      | 0      | 0       |
| House           | 🏢          | 200 stone 100 wood            | 7 - 12     | 0      | 0       |
| Theatre         | 🎭          | 150 wood                      | 0          | 150    | 0       |
| Church          | ⛪          | 200 wood 150 stone            | 0          | 300    | 0       |
| LumberjackHouse | 🪓          | 100 wood                      | 0          | 0      | 0       |
| StoneQuarry     | ⚒️          | 150 wood 100 stone            | 0          | 0      | 0       |
| IronMine        | ⛏️          | 200 wood 150 stone 100 iron   | 0          | 0      | 0       |
| SwordCraft      | ⚔️          | 400 wood, 100 stone, 300 iron | 0          | 0      | 250     |
| BowCraft        | 🏹          | 500 wood, 150 stone, 500 iron | 0          | 0      | 450     |


### Commands
  - **TownHall 🏛**
    - **0** - will write all avaible commands of Game
    - **1** - will print info about building
    - **2** - will create new building
    - **3** - will collect resources from extraction building
    - **90** - will exit from building
  - **Cottage 🏚**
    - **0** - will write all avaible commands of Game
    - **1** - will print info about building
    - **90** - will exit from building 
  - **House 🏢** 
    - **0** - will write all avaible commands of Game
    - **1** - will print info about building
    - **90** - will exit from building
  - **Church ⛪**
      - **0** - will write all avaible commands of Game
      - **1** - will print info about building
      - **90** - will exit from building
  - **Theatre 🎭**
      - **0** - will write all avaible commands of Game
      - **1** - will print info about building
      - **90** - will exit from building
  - **LumberjackHouse 🪓**
      - **0** - will write all avaible commands of Game
      - **1** - will print info about building
      - **2** - will mine terrain around building
      - **90** - will exit from building
  - **StoneMine ⚒️**
      - **0** - will write all avaible commands of Game
      - **1** - will print info about building
      - **2** - will mine terrain around building
      - **90** - will exit from building
  - **IronMine ⛏️**
      - **0** - will write all avaible commands of Game
      - **1** - will print info about building
      - **2** - will mine terrain around building
      - **90** - will exit from building
  - **SwordCraft ⚔️**
      - **0** - will write all avaible commands of Game
      - **1** - will print info about building
      - **90** - will exit from building
  - **BowCraft 🏹**
    - **0** - will write all avaible commands of Game
    - **1** - will print info about building
    - **90** - will exit from building  
  
## TERRAIN
| name         | appearance | wood | stone | iron |
|--------------|------------|------|-------|------|
| Forest       | 🌲         | 150  | 0     | 0    |
| Mountain     | ⛰️         | 0    | 150   | 150  |
| EmptyTerrain | ..         | 0    | 0     | 0    |
| SecretCave   | ..         | 0    | 0     | 1000 |
