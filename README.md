# What's SpaceDOS [Not real DOS]
- My first C++ project (please don't judge me harshly)
- A project to consolidate my C++ knowledge

Since version 1.8 Alpha uses NRC kernel (to create pseudo-OS)
 - Link to NRC: https://github.com/SpaceOC/NRC

# SpaceDOS
## Commands List
    - NRC -
    add_user, all_users_info, core_info, delete_user, user_info [username]
    help, logout (logging out of the current user account), rename_user, set_password [old (if a password is set)/new] [new ((if a password is set))],
    set_user_permissions [username] [new_permissions], edit_display_name [new_display_name] (changes the display name of the current user),
    time [command], whoim, create_file [full_path], delete_file [full_path], rename_file [full_path] [new_name]
    move_file [path] [new_path], show_file_data [full_path], create_folder [full_path],
    delete_folder [full_path], rename_folder [full_path] [new_name], move_folder [path] [new_path],
    show_folder_data [full_path], create_link_file [original_file_full_path] [file_name],
    create_link_folder [original_folder_full_path] [folder_name], tree, whereim, show_all, dir,
    search_file [what] [start-path (optional)], disk_size, cd [where]

    - SpaceDOS -
    counter, off, faf (folders and files), see_f [type (folders of files)], hello,
    logo, os_info, rsp (Rock, Scissors, Paper), set_user_permissions,
    settings, show_time, work_time, logs [type (in-os or in-file)], snake
