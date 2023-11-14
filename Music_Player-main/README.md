# Music_Player

This console-based Music Player application allows users to create playlists, play songs, manage playlists, and perform administrative tasks. The application supports basic functionalities like play, pause, next, previous, and playlist creation/update/deletion.

## Prerequisites

- **Operating System:** Windows
- **Compiler:** Any C++ compiler (e.g., Dev-C++, Code::Blocks, Visual Studio)

## Getting Started

1. Clone the repository to your local machine:
   ```bash
   git clone <repository_url>
   cd <repository_folder>
   ```

2. Compile and run the `main.cpp` file using your C++ compiler:
   ```bash
   g++ main.cpp -o MusicPlayer
   ./MusicPlayer
   ```

## Usage

1. **Create Playlist:**
   - Select option 1 to create a playlist.
   - Choose songs from the displayed list to add to your playlist.

2. **Play Songs:**
   - Select option 2 to play songs from the created playlist.
   - Use the on-screen menu to control playback (Play, Pause, Next, Previous).

3. **Update Playlist:**
   - Select option 3 to update your playlist.
   - You can add new songs or remove existing songs from the playlist.

4. **Delete a Song:**
   - Select option 6 and enter the admin password.
   - Choose option 2 to delete a song from the available list.

5. **Exit:**
   - Select option 5 to terminate the Music Player application.

## Admin Access

To access admin functionalities, enter the correct password when prompted. The default password is **hello**.

## Note

- Songs added to the playlist should be in the same directory as the executable or provide the full path while adding songs.
- This application is specifically designed for Windows operating systems and may not work as expected on other platforms.

## Contributing

Feel free to contribute to this project by suggesting improvements or reporting issues. Pull requests are welcome!
