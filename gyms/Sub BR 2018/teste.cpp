for ($i=2; $i -le 26; $i++) {
    echo "Doing test case" $i

    Rename-Item -Path "C:\\Users\\dany1\\OneDrive\\Documentos\\Coding\\Learning\\gyms\\Sub BR 2018\\contest_tests\\L\\input\\L_$i" -NewName "L.in"
    Rename-Item -Path "C:\\Users\\dany1\\OneDrive\\Documentos\\Coding\\Learning\\gyms\\Sub BR 2018\\contest_tests\\L\\output\\L_$i" -NewName "L_gab.out"

    Start-Process -FilePath "./01.exe" -NoNewWindow
    Start-Process -FilePath "./ver.exe" -NoNewWindow

    timeout /t 1
    
    Rename-Item -Path "C:\\Users\\dany1\\OneDrive\\Documentos\\Coding\\Learning\\gyms\\Sub BR 2018\\contest_tests\\L\\input\\L.in" -NewName "L_$i"
    Rename-Item -Path "C:\\Users\\dany1\\OneDrive\\Documentos\\Coding\\Learning\\gyms\\Sub BR 2018\\contest_tests\\L\\output\\L_gab.out" -NewName "L_$i"
}