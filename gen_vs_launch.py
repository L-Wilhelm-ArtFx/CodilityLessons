import os
import json

conf = [
	{
		"name": "Populate launch.json",
		"type": "python",
		"request": "launch",
		"program": "${workspaceFolder}\\gen_vs_launch.py",
		"cwd": "${workspaceFolder}",
	},
]

for f in os.listdir("./build/Debug"):
	if not f.endswith(".exe"):
		print(f"Skip {f}")
		continue

	conf.append({
		"name": f + " - (Windows) Lancer",
		"type": "cppvsdbg",
		"request": "launch",
		"program": "${workspaceFolder}\\build\\Debug\\"+f,
		"args": [],
		"stopAtEntry": False,
		"cwd": "${workspaceFolder}",
		"environment": [],
		"externalTerminal": True
	})
	print(f"Add target {f}")

launchconf = {
	"version": "0.2.0",
	"configurations": conf,
}

with open('./.vscode/launch.json', 'w') as f:
    f.write(json.dumps(launchconf, indent=4))