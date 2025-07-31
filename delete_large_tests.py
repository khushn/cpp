import sys
from pathlib import Path

def delete_large_tests(folder_path, size_kb=10):
    folder = Path(folder_path)
    size_limit = size_kb * 1024  # bytes

    deleted = []

    for in_file in folder.glob("*.in"):
        if in_file.stat().st_size > size_limit:
            base = in_file.stem  # e.g., "0" from "0.in"
            out_file = folder / f"{base}.out"
            out_my_file = folder / f"{base}.out.my"

            in_file.unlink()
            if out_file.exists():
                out_file.unlink()
            if out_my_file.exists():
                out_my_file.unlink()

            deleted.append(base)

    if deleted:
        print(f"🗑 Deleted large test cases: {', '.join(deleted)}")
    else:
        print("✅ No large test cases found (over 10 KB).")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python delete_large_tests.py <folder_path>")
        sys.exit(1)

    delete_large_tests(sys.argv[1])

