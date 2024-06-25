# RunasCpp

This is a C++ version of [antonioCoco](https://github.com/antonioCoco)'s [RunasCs](https://github.com/antonioCoco/RunasCs) I made without looking at the original sourcecode.
It's not really anything revolutionary but I wanted to learn how it works and write one from scratch to see if I'd be able to figure it out.

## How to use it
The tool supports the following arguments (not necessarily in this order)
```
--username    - username of the user you want to run the process as
--password    - password of the user you want to run the process as
--processpath - path of the binary to execute
--domain      - domain of the user to impersonate
                if a domain is not defined the tool will automatically default to the local hostname
--args        - string of arguments to pass to the binary specified in `--processpath`
```

## Demo

https://github.com/otterpwn/RunasCpp/assets/54770684/12f1ad9f-c02d-4720-9a90-fb42cb404718

![VirusTotal Results](https://github.com/otterpwn/RunasCpp/assets/54770684/d598756d-6b04-410c-8edd-3a8e5140597f)

![Kleenscan Results](https://github.com/otterpwn/RunasCpp/assets/54770684/646e9704-27f6-4947-b792-858d26df6d11)
