from datetime import datetime

from crtime import get_crtimes_in_dir

for fname, timestamp in get_crtimes_in_dir(".", raise_on_error=True, as_epoch=False):
    # Convert the timestamp to a datetime object
    dt_object = datetime.fromtimestamp(timestamp)

    # Format the datetime object as a string
    date_str = dt_object.strftime("%Y-%m-%d %H:%M:%S")
    print(fname, date_str)
