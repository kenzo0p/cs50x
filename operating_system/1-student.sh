#!/bin/sh

op=0

while [ $op -ne 7 ]
do
    echo "1) Create DB"
    echo "2) Add Record"
    echo "3) Display DB"
    echo "4) Search"
    echo "5) Delete"
    echo "6) Modify"
    echo "7) Exit"
    echo "Enter choice:"
    read op

    case $op in

    1)
        echo "Enter DB Name:"
        read db
        > $db
        echo "Database Created."
        ;;

    2)
        echo "Enter DB Name:"
        read db
        echo "Enter ID:"
        read id
        echo "Enter Name:"
        read nm
        echo "Enter Phone:"
        read ph
        echo "$id $nm $ph" >> $db
        echo "Record Added!"
        ;;

    3)
        echo "Enter DB Name:"
        read db
        cat $db
        ;;

    4)
        echo "Enter DB Name:"
        read db
        echo "Enter Phone no:"
        read ph
        grep "$ph" $db
        ;;

    5)
        echo "Enter DB Name:"
        read db
        echo "Enter Phone to delete record:"
        read ph
        grep -v "$ph" $db > temp
        mv temp $db
        echo "Record Deleted!"
        ;;

    6)
        echo "Enter DB Name:"
        read db
        echo "Enter Phone to modify record:"
        read ph
        grep -v "$ph" $db > temp
        echo "Enter new ID:"
        read id
        echo "Enter new Name:"
        read nm
        echo "Enter new Phone:"
        read ph1
        echo "$id $nm $ph1" >> temp
        mv temp $db
        echo "Record Modified!"
        ;;

    7)
        echo "Exiting..."
        ;;

    *)
        echo "Invalid option"
        ;;
    esac
done
