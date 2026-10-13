import os, shlex, subprocess, sys

while True:
    try:
        cmd = input(f"\nmini-shell:{os.getcwd()}$ ").strip()
        if not cmd:
            continue
        tokens = shlex.split(cmd)
        if tokens[0] in ("exit", "quit"):
            break
        if tokens[0] == "cd":
            os.chdir(tokens[1] if len(tokens) > 1 else os.path.expanduser("~"))
        else:
            subprocess.Popen(
                tokens, stdout=sys.stdout, stderr=sys.stderr, stdin=sys.stdin
            ).wait()
    except Exception as e:
        print(f"error: {e}")
