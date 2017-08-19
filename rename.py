"""Use to rename directories of form Weekx-Sx-YEAR-Topics to YEAR-Sx-Weekx-Topics
so file explorers lists them in order :)."""
import os
import re

FOLDER_PATTERN = r"^Week\d-S\d-\d{4}-\w+"
FOLDER_PATTERN_MATCH = re.compile(FOLDER_PATTERN)
IGNORED = {".git", ".", "..", "rename.py", "resources.md"}

def re_structure_project(absoluate_current_dir):
    """Re structure project so that directories of form Weekx-Sx-YEAR-Topics
    are changed to YEAR-Sx-Weekx-Topics so file explorers lists them in order.
    There are also randomly named *.md files, if only one of them exists in
    bottom level directories, rename them to README.md so it reders on GitHub.
    """
    files = os.listdir(absoluate_current_dir)
    directories = [f for f in files if f not in IGNORED and os.path.isdir(
                os.path.join(absoluate_current_dir, f))]

    if directories:  # Not a bottom level directory.
        for directory in directories:
            re_structure_project(os.path.join(absoluate_current_dir, directory))
            # Try rename the directory.
            process_directory(os.path.join(absoluate_current_dir, directory))
    else:
        # Base case: Current directory we are in is a bottom level directory.
        process_markdown_files(absoluate_current_dir)

def process_directory(absoluate_path_to_dir):
    prefix, directory = absoluate_path_to_dir.rsplit(os.path.sep, 1)

    if not FOLDER_PATTERN_MATCH.match(directory):
        return

    dir_name = directory.split("-")
    new_name = "-".join([dir_name[2], dir_name[1], dir_name[0]])
    suffix = "-".join(dir_name[3:])
    new_name = new_name + "-" + suffix
    os.rename(os.path.join(prefix, directory), os.path.join(prefix, new_name))

def process_markdown_files(absoluate_path_to_bottom_level_dir):
    files = os.listdir(absoluate_path_to_bottom_level_dir)
    re_pattern = r"^\w+.md"
    re_pattern = re.compile(re_pattern)
    potential_readmes = []
    for f in files:
        if re_pattern.match(f):
            potential_readmes.append(f)
    if len(potential_readmes) > 1:
        return  # Don't know which one should be readme.
    if not potential_readmes:
        return  # No mark down files ¯\_(ツ)_/¯.
    os.rename(
        os.path.join(absoluate_path_to_bottom_level_dir, potential_readmes[0]),
        os.path.join(absoluate_path_to_bottom_level_dir, "README.md")
    )


if __name__ == "__main__":
    re_structure_project(os.getcwd())
