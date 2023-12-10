# campus Epidemic Prevention System
c, DUT CS Course Programming Basis

## Project Overview
This project is a C implementation of a system meticulously designed to bolster epidemic prevention and control efforts within university campuses amid the COV pandemic. Its core objective is to establish a robust and streamlined platform for the effective management and secure storage of vital information pertinent to COV mitigation within educational institutions. The system adeptly handles a wide array of data types, encompassing personal student particulars, daily health assessments, results of nucleic acid tests, vaccination documentation, and leave requests – all critical elements in the context of the pandemic.

### Features
Key features of this comprehensive system include intuitive data entry, precise search capabilities, seamless editing, secure deletion, efficient sorting mechanisms, insightful graphical statistical analyses, and a password-protected login, ensuring both functionality and security in this critical application.

## User Guide
### Pre-Run Setup
- **Environment:** Windows 10 – Microsoft Visual C++ 2010 Express.
- **Executable Path:** Can be run from any directory after unzipping the package.
- **File Composition:** Main executable, `password.txt` (for password storage), `data.txt` (for storing student information).

### Operating Instructions
- **Login Interface:** Initial run sets default password to “123”. Subsequent runs require login with a maximum of three password attempts.
- **Menu Interface:** Consists of three sections: “Edit”, “Statistics”, and “About”. Switch between them using T or t.
- **Features:** Includes viewing student information, querying, editing, deleting personal information, sorting, adding various records, clearing data, and exiting the system.
- **Statistical Information:** Presents nucleic acid tests, vaccinations, and leave applications in a bar chart format.

## Design and Implementation
- **Structure Design:** Overall program logic flow, data description (structures, buffer strings, etc.), and module design.
- **Data Processing:** Utilizes arrays, string operations, file I/O, and custom functions for data handling and storage.
- **User Interface:** Basic console interface design using tabs for table-formatted output.

## Challenges and Solutions
- **Table Design:** Utilizes tabs for table display in a text-only console, enhancing data presentation.
- **Interface Aesthetics:** Improving the console interface appearance remains a challenge, aiming for more advanced interactive features like key inputs and mouse operations.

## Performance and Limitations
- **Stability:** The program runs stably with functionalities meeting the expectations.
- **Areas for Improvement:** User interface design can be enhanced for better interaction and visual appeal.

## Contributing
Contributions to the project are welcome! Please follow these steps:
1. Fork the repository
2. Create a new branch
3. Make your changes and commit them
4. Push to the original branch
5. Create the pull request

Alternatively, see the GitHub documentation on [creating a pull request](https://docs.github.com/en/github/collaborating-with-issues-and-pull-requests/creating-a-pull-request).

## License
This project is licensed under the [MIT License](LICENSE.md) - see the LICENSE file for details.
