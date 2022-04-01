# How to build

## Build Environment
- Qt 6.2.1
- Qt Creator
- MSVC 2019

## Create a Windows installer

Prerequisite:
Make sure you have the [Qt Installer Framework](https://doc.qt.io/qtinstallerframework/ifw-overview.html) installed
Steps:

1. Build the Application in Release Mode
2. Copy the `CoviDusWidget.exe` File to the Installer folder below packages/de.jjp.covidus/data
3. Open the Command Prompt with the Build Environment and navigate to the copied `CoviDusWidget.exe` File
4. execute the command `windeployqt CoviDusWidget.exe`. This command will copy all relevant files to the folder and replace all absolute depedencies with relative ones. If
`windeployqt` is not found, check `<QtInstallationPath>/<version>/msvc2019_64/bin/windeployqt.exe`.
5. navigate to the root of the installer folder
6. execute the command `<QtInstallationPath>/Tools/QtInstallerFramework/<Version>/bin/binarycreator.exe --offline-only -c config/config.xml -p packages <Application>.exe`
7. After the execution of the command the installer should have been created
8. Test the installer


## Host Server by Yourself
You can either use the default server configuration (api.corona-zahlen.org) or host the server by your self, as described by Marlon Lückert [see here](https://api.corona-zahlen.org/docs/#host-it-yourself).

```yaml
version: "3.8"
networks:
  redis-net:
services:
  redis:
    image: redis
    container_name: cache
    expose:
      - 6379
    networks:
      - redis-net
  rki-api:
    image: marlon360/rki-covid-server:v2
    ports:
      - "8080:3000"
    depends_on:
      - redis
    environment:
      - REDISHOST=redis
    networks:
      - redis-net
```
