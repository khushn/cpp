import sys
import subprocess
from pathlib import Path
import filecmp

def run_tests(folder_path):
    folder = Path(folder_path)
    a_out = folder / 'a.out'

    if not a_out.exists():
        print("Error: a.out not found in the folder.")
        return

    test_cases = sorted(folder.glob("*.in"))
    failed = []

    for test_case in test_cases:
        test_number = test_case.stem  # e.g., "0" from "0.in"
        output_file = folder / f"{test_number}.out"
        my_output_file = folder / f"{test_number}.out.my"

        with open(test_case, 'r') as infile, open(my_output_file, 'w') as outfile:
            subprocess.run([str(a_out)], stdin=infile, stdout=outfile)

        # Compare expected and generated output
        if not output_file.exists():
            print(f"Warning: Expected output file {output_file.name} not found.")
            failed.append(test_number)
        elif not filecmp.cmp(output_file, my_output_file, shallow=False):
            failed.append(test_number)

    if failed:
        print("❌ Test cases failed:", ", ".join(failed))
    else:
        print("✅ All test cases passed.")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python run_tests.py <folder_path>")
        sys.exit(1)

    run_tests(sys.argv[1])

