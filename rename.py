"""Use to rename diretories of form Weekx-Sx-YEAR-Topics to YEAR-Sx-Weekx-Topics so file explorers lists them in order :)."""
import os
import re


def rename():
    RE_PATTERN = "^Week\d-S\d-\d{4}-\w+"

    re_match = re.compile(RE_PATTERN)

    top_level_dirs = os.listdir()
    IGNORE = { ".git", ".", "..", "rename.py", "resources.md" }
    path = os.getcwd()

    for directory in top_level_dirs:
        if not os.path.isdir(os.path.join(path, directory)):
            continue
        if not re_match.match(directory):
            continue
        dir_name = directory.split("-")
        new_name = "-".join([dir_name[2], dir_name[1], dir_name[0]])
        suffix = "-".join(dir_name[3:])
        new_name = new_name + "-" + suffix
        # os.rename(os.path.join(path, directory), os.path.join(path, new_name))

if __name__ == "__main__":
    rename()
