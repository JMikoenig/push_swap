import subprocess

payloads = [
    ("a non valid string", "Error\n"),
    ("1 2", ""),
    ("3 1 2", "ra\n"),
    ("", "")
]

def main(*arg, **kwarg):
    print("Starting test")
    for i, p in enumerate(payloads):
        print(f"test case {i + 1}")
        test_case(p[0], p[1])

def call_push_swap(*arg):
    proc = subprocess.run(["echo",  *arg], capture_output=True)
    push_swap_args = proc.args
    print(f"The push_swap command has been called with the following argument(s): {push_swap_args[1:]}")
    stdout = proc.stdout.strip().decode("utf-8")
    print(f"output of the execution {stdout}")
    return str(stdout)



def test_case(payload, expected_output):
    try:
        output = call_push_swap(payload)
        print("-------------------------------------")
        print(f"expected_output: {expected_output}")
        print(f"actual output: {output}")
        print("-------------------------------------")
        assert(expected_output == output)
        check_common_restrictions(payload, output)
    except Exception as e:
        print(e)


def check_common_restrictions(payload, output):
    n_commands = len(output.split())
    if type(payload) == str:
        input_numbers = payload.split()
        if len(input_numbers) <= 100:
            assert(n_commands <= 700)
        if len(input_numbers) <= 500:
            assert(n_commands <= 5500)
    
    



if __name__ == "__main__":
    main()



"""
> push swap 5 6 3 0
> push swap "2 45 7"
"""